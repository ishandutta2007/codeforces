#include<iostream>
#include<cmath> 
#include<cstdio>
#include<algorithm>
//#include <queue>
#define N 400005
#define MM 1000000009
#define INF 0x4fffffff
#define PI 3.14159265358979323846

#define rep(i,j,k) for(i=j;i<=k;i++)
#define rrep(i,j,k) for(i=j;i>=k;i--)

using namespace std;

int n,i,a[100],flag;
char s[1000];

int main(){
	cin>>n;
	gets(s);
	gets(s);
	rep(i,0,25)
		a[i]=0;
	rep(i,0,n-1){
		if (s[i]<='Z')
			a[s[i]-'A']++;
		else
			a[s[i]-'a']++;
	}
	flag=1;
	rep(i,0,25)
		if (a[i]==0)
			flag=0;
	if (flag)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
	return 0;
}