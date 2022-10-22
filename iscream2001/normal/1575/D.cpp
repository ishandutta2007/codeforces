#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ans=0;
char s[100],s1[100];
int n;
void check(){
	if(s1[1]=='0')return;
	int tag=-1;
	ll num=1;
	for(int i=n-1;i<=n;++i){
		if(s[i]=='_')continue;
		else if(s[i]=='X'){
			if(tag==-1)tag=s1[i];
			else if(tag!=s1[i])num=0;
		}
		else if(s1[i]!=s[i])num=0;
	}
	if(n>2){
		if(s[1]=='0')num=0;
		if(s[1]=='X'){
			if(tag==-1)tag=-2;
			else if(tag=='0')num=0;
		}
		if(s[1]=='_')num=num*9;
	}
	int tg=0;
	for(int i=2;i<n-1;++i)if(s[i]=='_')num=num*10;
	for(int i=1;i<=n;++i)if(s[i]=='X')tg=1;
	if(!tg)tag=0;
	if(tag==-1)num=num*10;
	if(tag==-2)num=num*9;
	ans+=num;
}
int main()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	if(n==1){
		if(s[1]=='_'||s[1]=='X'||s[1]=='0')puts("1");
		else puts("0");
		return 0;
    }
    for(int i=1;i<=n;++i)s1[i]=0;
    s1[n-1]='0';s1[n]='0';
    check();
    for(int i=1;i<=n;++i)s1[i]=0;
    s1[n-1]='2';s1[n]='5';
    check();
    for(int i=1;i<=n;++i)s1[i]=0;
    s1[n-1]='5';s1[n]='0';
    check();
    for(int i=1;i<=n;++i)s1[i]=0;
    s1[n-1]='7';s1[n]='5';
    check();
    cout<<ans;
	return 0; 
}

/*%4=0
0110
1001 */ 
//0110 1001 1001