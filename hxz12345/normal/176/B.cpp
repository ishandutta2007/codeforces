#include<bits/stdc++.h>
using namespace std;
string s,s1,s2;
long long jt,n,Q,MOD,i,j,sum,sum1,sum2,sum3,f[100010][3];
bool flag;
int main()
{
	ios::sync_with_stdio(0);cin.tie();cout.tie();
	cin>>s1;
	cin>>s2;
	cin>>Q;MOD=1000000007;
	n=s1.size();
	// s1->s2
	for (i=1;i<=n;i++)
         {
             flag=true;jt=0;
             for (j=i;j<n;j++) 
                if (s1[j]!=s2[jt])
                    {
                    	flag=false;break;
					}
			else jt++;
             for (j=0;j<i;j++) 
                 if (s1[j]!=s2[jt])
                     {
                     	flag=false;break;
					 }
			else jt++;
			sum+=flag;
         }
    //s2->s2
    for (i=1;i<=n;i++)
         {
             flag=true;jt=0;
             for (j=i;j<n;j++) 
                if (s2[j]!=s2[jt])
                    {
                    	flag=false;break;
					}
			else jt++;
             for (j=0;j<i;j++) 
                 if (s2[j]!=s2[jt])
                     {
                     	flag=false;break;
					 }
			else jt++;
			sum1+=flag;
         }
    //s2->s1
    for (i=1;i<=n;i++)
         {
             flag=true;jt=0;
             for (j=i;j<n;j++) 
                if (s2[j]!=s1[jt])
                    {
                    	flag=false;break;
					}
			else jt++;
             for (j=0;j<i;j++) 
                 if (s2[j]!=s1[jt])
                     {
                     	flag=false;break;
					 }
			else jt++;
			sum2+=flag;
         }
    //s1->s1
    for (i=1;i<=n;i++)
         {
             flag=true;jt=0;
             for (j=i;j<n;j++) 
                if (s1[j]!=s1[jt])
                    {
                    	flag=false;break;
					}
			else jt++;
             for (j=0;j<i;j++) 
                 if (s1[j]!=s1[jt])
                     {
                     	flag=false;break;
					 }
			else jt++;
            sum3+=flag;
         }
    if (s1==s2) f[0][0]=1;
    else f[0][1]=1;
    for (i=1;i<=Q;i++)
        {
        	f[i][0]=(f[i-1][1]*sum % MOD+f[i-1][0]*(sum-1) % MOD) % MOD;
			f[i][1]=(f[i-1][0]*(n-sum) % MOD+f[i-1][1]*(n-sum-1) % MOD) % MOD; 
		}
	//	f[i][0]=f[i-1][1]
	cout<<f[Q][0]<<endl;
	return 0;
}