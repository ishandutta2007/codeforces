// Hydro submission #6253b33248f783013279127a@1649652531524
#include<bits/stdc++.h>
using namespace std;
int s[100][3],k[100];
int main()
{
    int n,i,j;
    cin>>n;
    for(i=0;i<n;i++)
    for(j=0;j<3;j++)
    cin>>s[i][j];
    for(j=0;j<3;j++)
    for(i=0;i<n;i++)
    k[j]+=s[i][j];
    for(i=0;i<n;i++)
    if(k[i])
	{
		printf("NO\n");
		return 0;
	}
    printf("YES\n");
    return 0;
}