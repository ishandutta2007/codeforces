#include <iostream>
#include <string>
#include <map>
#include <math.h>
#include <vector>
#include <algorithm>

using namespace std;

#define sqr(x) ((x)*(x))

int gcd(int a,int b) {
	if (a*b==0) return a+b;
	return gcd(b%a,a);
}



/*int n,k;
int b[9],vis[9];
string a[9],c[9];
int ans=1e9;

void rec(int x) {
	if (x==k) {
		int mi=1e9,ma=0;
		for (int i=1; i<=n; i++) {
			c[i]="";
			c[i]+='0';
			for (int j=1; j<=k; j++)
				c[i]+=a[i][b[j]-1];
			int p=0;
			string s=c[i];
			sscanf(s.c_str(), "%d", &p);
			mi=min(mi,p);
			ma=max(ma,p);
		}
		ans=min(ans,ma-mi);
	}
	else {
		for (int i=1; i<=k; i++) {
			if (!vis[i]) {
				b[x+1]=i;
				vis[i]=true;
				rec(x+1);
				b[x+1]=0;
				vis[i]=false;
			}
		}
	}
}*/


map <char,int> a;
vector <pair<int,char>> v;
vector <pair<int,char>> d[100];
int n,sum;
bool used[2000];
string ans="";

bool pr(int x) {
	for (int i=2; i<=sqrt(x*1.0); i++) 
		if (!(x%i)) return false;
	return true;
}

void get(int count, int x, char c) {
	d[count].push_back(make_pair(x,c));
	used[x]=true;
	for (int i=x; i<=n; i+=x) {
		for (int j=2; j<=i; j++) {
			if (!used[j] && !(i%j)) 
				get(count,j,c);
		}
		used[i]=true;
		if (ans[i-1]=='0') {
			ans[i-1]=c;
			sum++;
		}
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);	
	freopen("output.txt", "w", stdout);
#endif
	string s;
	cin >> s; n=s.size();
	for (int i=0; i<n; i++) ans+='0';
	for (int i=0; i<s.length(); i++)
		a[s[i]]++;
	for (char c='a'; c<='z'; c++) {
		v.push_back(make_pair(a[c],c));
	}
	sort(v.begin(),v.end());
	int count=1; bool f=true,f1=false;
	for (int i=2; i<=n; i++) {
		if (!used[i] && pr(i)) {
			sum=0;
			get(count,i,v.back().second);
			pair<int,char> o=v.back(); o.first-=sum;
			v.pop_back(); v.push_back(o);
			sort(v.begin(), v.end());
		}
	}
	ans[0]=v.back().second;
	pair<int,char> o=v.back(); o.first-=1;
	v.pop_back(); v.push_back(o);
	sort(v.begin(), v.end());
	if (v[0].first<0) f=false;
	else f=true;
	/*for (int i=1; i<=s.length(); i++) ans+='0';
	for (int i=2; i<=s.length(); i++) {
		if (pr(i)) {
			for (int j=1; j<=(n/i); j++) {
				ans[i*j-1]=v.back().second;
			}
			if (n/i>v.back().first) f=false;
			pair<int,char> k=v.back(); k.first-=n/i;
			v.pop_back();
			v.push_back(k);
			sort(v.begin(),v.end());
			count++;
		}
	}
	if (1>=v.back().first || f1) ans[0]=v.back().second;*/
	if (f) {
		cout << "YES" << endl;
		cout << ans;
	}
	else {
		cout << "NO";
	}
	/*cin >> n >> k;
	for (int i=1; i<=n; i++) cin >> a[i];
	rec(0);
	cout << ans;*/
	return 0;
}