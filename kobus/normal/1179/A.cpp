#include <bits/stdc++.h>
using namespace std;
#define INF 1'000'000'001
#define f first
#define s second
#define eps 1e-6
#define pb push_back
#define pii pair<int,int>
#define one 1
#define mp make_pair
#define ld long double
#define MAXN 2123456
#define mod 998244353 
#define int long long
#define ld long double
#define pi acos(-1)

pii num[MAXN];
pii num2[MAXN];
deque<int> dq;
int maxi=-1;
bool dm=0;
int i=0;
int i2=0;
int n,q;

void prep(){
	//cout<<maxi<<endl;
	while(dq.front()!=maxi){
		//cout<<"front "<<dq.front()<<endl;
		int a=dq.front();
		dq.pop_front();
		int b=dq.front();
		dq.pop_front();
		num[i]={a,b};
		if(a<b)swap(a,b);
		dq.push_front(a);
		dq.push_back(b);
		i++;
	}
	for(int i3=0;i3<n-1;i3++){
		int a=dq.front();
		dq.pop_front();
		int b=dq.front();
		dq.pop_front();
		num2[i2]={a,b};
		if(a<b)swap(a,b);
		dq.push_front(a);
		dq.push_back(b);
		i2++;
	}
}

pii ans(int x){
	x--;
	if(x<i){
		cout<<num[x].f<<" "<<num[x].s<<endl;
	}
	else{
		x-=i;
		x%=n-1;
		cout<<num2[x].f<<" "<<num2[x].s<<endl;
	}
}


int32_t main(){

	cin>>n>>q;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		maxi=max(maxi,x);
		dq.push_back(x);
	}
	prep();
	//cout<<i<<" "<<i2<<endl;
	for(int i=0;i<q;i++){
		int m;
		cin>>m;
		ans(m);
	}

    return 0;
}