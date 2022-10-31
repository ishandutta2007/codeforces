// Hydro submission #62591c5fcc64917dc466506e@1650007136425
#include<bits/stdc++.h>
using namespace std;
string c[10]={"Danil","Olya","Slava","Ann","Nikita"};
int main()
{
    string s;
    int t=0,n;
    cin>>s;
    for(int i=0;i<5;i++)
    {
        n=0;
        while(s.find(c[i],n)!=-1)
		t++,n=s.find(c[i],n)+1;
    }
    if(t-1) printf("NO\n");
    else printf("YES\n");
    return 0;
}