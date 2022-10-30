// Hydro submission #625ceedcfa9408d417feabdf@1650257628189
#include<bits/stdc++.h>
using namespace std;
int b,p,f,h,c,s;
void fh()
{
    while(p&&b>1)
    {
        s+=h;
        p--,b-=2;
    }
}
void fc()
{
    while(f&&b>1)
    {
        s+=c;
        f--,b-=2;
    }
}
int main()
{
    int t,x,i;
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>b>>p>>f>>h>>c;
        x=min(h,c);s=0;
        if(!p&&!f||b<2)
        {
            printf("0\n");
            continue;
        }
        else if(h>c)
        fh(),fc();
        else if(h<c)
        fc(),fh();
        else
        s+=min((p+f)*2,b)/2*x;
        printf("%d\n",s);
    }
    return 0;
}