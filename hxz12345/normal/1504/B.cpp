#include<bits/stdc++.h>
using namespace std;
int c[500000],a[500000],b[500000],T,len,i,j,p1,p2;
bool flag2,flag1,flag,check;
string s;
int w;
bool f[500000];
int main()
{
	cin>>T;
	while (T)
	    {
	    	cin>>len;
	        cin>>s;
	        for (i=1;i<=len;i++) f[i]=false;
	        for (i=1;i<=len+1;i++) 
	             {
	             	a[i]=0;b[i]=0;
				 }
	        for (i=1;i<=len;i++) { if (s[i-1]=='0') a[i]=0;else a[i]=1;c[i]=c[i-1]+a[i];}
			cin>>s;
			for (i=1;i<=len;i++) { if (s[i-1]=='0') b[i]=0;else b[i]=1;}
			flag1=true;flag2=true;w=0;
			for (i=1;i<=len;i++)
			    if ((i % 2==0))
			        if ((c[i]==i/2))
			           f[i]=true;
		    for (i=2;i<=len+1;i++)
		         if (((a[i]!=b[i])&(a[i-1]==b[i-1]))||((a[i]==b[i])&(a[i-1]!=b[i-1])))
					  if (f[i-1]==false)
		                  {
		                  	flag2=false;break;
						  }
			if ((len==1)&(a[1]!=b[1])) cout<<"NO"<<endl;
			else if (flag2==false) cout<<"NO"<<endl;
			else cout<<"YES"<<endl;
			T--;
		}
	return 0;
}