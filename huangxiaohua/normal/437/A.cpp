#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,a,b,c,d,res;
char sb[105];
int main(){
	gets(sb);a=strlen(sb)-2;
	gets(sb);b=strlen(sb)-2;
	gets(sb);c=strlen(sb)-2;
	gets(sb);d=strlen(sb)-2;
	
	if(a*2<=b&&a*2<=c&&a*2<=d){res+=1;}
	if(b*2<=a&&b*2<=c&&b*2<=d){res+=2;}
	if(c*2<=a&&c*2<=b&&a*2<=d){res+=4;}
	if(d*2<=a&&d*2<=b&&d*2<=c){res+=8;}
	
	if(a>=b*2&&a>=c*2&&a>=d*2){res+=1;}
	if(b>=a*2&&b>=c*2&&b>=d*2){res+=2;}
	if(c>=a*2&&c>=b*2&&c>=d*2){res+=4;}
	if(d>=a*2&&d>=b*2&&d>=c*2){res+=8;}
	
	if(res==1){puts("A");return 0;}
	if(res==2){puts("B");return 0;}
	if(res==4){puts("C");return 0;}
	if(res==8){puts("D");return 0;}
	
	puts("C");
}