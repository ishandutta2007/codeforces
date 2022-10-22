#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define LL long long
using namespace std;
const int N=2e5+10;
int n;
char s1[N],s2[N];
int x=0,y=0;
int l[N<<2],r[N<<2];
int main(){
	scanf("%d",&n);
	scanf("%s",s1+1);
	scanf("%s",s2+1);
	for(int i=1;i<=n;++i){
		if(s1[i]!=s2[i]) ++x;
	}
	//cout<<x<<endl;
	if(x&1) cout<<-1<<endl;
	else{
		for(int i=1,j=1;i<=n&&j<=n;++i){
			if(s1[i]=='a'&&s2[i]=='b'){
				while(s1[j]!='a'||s2[j]!='b'||j==i) {++j;if(j>n)break;}
				if(j<=n)
				{
					++y;
				l[y]=i;r[y]=j;
				swap(s1[i],s2[j]);
				}
			}
		}
		for(int i=1,j=1;i<=n&&j<=n;++i){
			if(s1[i]=='b'&&s2[i]=='a'){
				while(s1[j]!='b'||s2[j]!='a'||j==i) {++j;if(j>n)break;}
				if(j<=n)
				{
				++y;
				l[y]=i;r[y]=j;
				swap(s1[i],s2[j]);}
			}
		}
		//cout<<y<<endl;
		for(int i=1,j=1;i<=n&&j<=n;++i){
			if(s1[i]=='a'&&s2[i]=='b'){
				while(s1[j]!='b'||s2[j]!='a'||j==i) {++j;if(j>n)break;}
				if(j<=n)
				{
				++y;
				l[y]=j;r[y]=j;
				swap(s1[j],s2[j]);
				
			++y;
				l[y]=i;r[y]=j;
				swap(s1[i],s2[j]);}
			}
		}
		cout<<y<<endl;
		for(int i=1;i<=y;++i) printf("%d %d\n",l[i],r[i]);
	}
}