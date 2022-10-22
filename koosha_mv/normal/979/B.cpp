#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define is_bit(x,y) (x%(1<<(y+1))>=(1<<y))
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(int i=a;i<b;i++)
#define get(x) scanf("%I64d",&x);
#define gett(x) scanf("%d",&x);																																														
#define ops(x) cout<<x<<" !"<<endl;
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define Add(x,y) x=(x+y)%mod;
#define lst(x) x[x.size()-1]
#define Sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

int n, k, t, mxl, pos, num;
string str, nam[4];
map<char, int> m;
 
int main() {
	cin >> n;
	nam[0] = "Kuro";
	nam[1] = "Shiro";
	nam[2] = "Katie";
	nam[3] = "Draw";
	for(int i = 0; i < 3; i ++) {
		cin >> str;
		k = str.length(), t = 0;
		m.clear();
		for(int j = 0; j < k; j ++)
			t = max(t, ++ m[str[j]]);
		if(n == 1 && k == t)
			num = k - 1;
		else
			num = min(k, n + t);
		if(mxl < num)
			mxl = num, pos = i;
		else if(mxl == num)
			pos = 3;
	}
	cout << nam[pos] << endl;
	return 0;
}