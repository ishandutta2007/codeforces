#include<bits/stdc++.h>
using namespace std;
long long tab[1005];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    long long a,b,licz=0,pom1,pom2,zero=0;
    cin>>a>>b;
    for(int x=1;x<=b;x++)
        tab[x]=(x*x)%b;
    for(int x=1;x<=b;x++)
        for(int y=1;y<=b;y++)
            if((tab[x]+tab[y])%b==0)
            {
                pom1=a/b;
                pom2=a/b;
                if(a%b>=x)
                    pom1++;
                if(a%b>=y)
                    pom2++;

                licz+=pom1*pom2;
            }
    cout<<licz;
    return 0;
}