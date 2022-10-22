#include<iostream>
#include<cstring>
using namespace std;

char a[200000],b[200000];
int kmp[200000];
int n,m,i,j,first,curr,val[200000],l;
int dyn[200000];
int sum[200000];
int MOD = 1000000007;

int main(void){
    cin >> b >> a;
    n=strlen(a);
    m=strlen(b);
    kmp[0]=1;
    if (n==1)
    {
        for(i=0;i<=m-1;i++)
            {
                if (a[0]==b[i])
                    {
                        l++;
                        val[l]=i;
                    }
            }
    }
	else{
	    for(i=1;i<=n-1;i++)
		{
		   j=kmp[i-1];
		   while(j<i&&a[i]!=a[i-j])
		   j+=kmp[i-1-j];
		   if (j==i) {if (a[i]==a[0]) kmp[i]=i; else kmp[i]=i+1;}
		   else kmp[i]=j;
	 
		}
	    if (a[0]==b[0]) {first=0;}
	    else {first=1;}
	    for(i=1;i<=m-1;i++)
		{
		    while(first<i&&b[i]!=a[i-first]) first+=kmp[i-1-first];
		    if (first==i) {if (b[i]==a[0]) first=i; else first=i+1;}
		    if (i-first==n-1)
		    {l++;val[l]=first;
		     first+=kmp[n-1];
		    }
		}
	 }

     val[0] = -1; 
     dyn[m] = 0;
     sum[m] = 1;
     for (i=m-1;i>=0;i--){
        while (l > 1 && val[l-1] >= i) l--;
        if (val[l] >= i){
            dyn[i] = dyn[i+1] + sum[val[l]+n];
            if (dyn[i] >= MOD) dyn[i] -= MOD;
            sum[i] = sum[i+1] + dyn[i] + 1;
            if (sum[i] >= MOD) sum[i] -= MOD;
        }
        else{
            dyn[i] = 0;
            sum[i] = sum[i+1] + 1;
        }
     }

     cout << dyn[0];

     return 0;
}