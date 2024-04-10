#include <iostream>
using namespace std;

int is[230][230];
int is1[230];
int is2[230];
char a[200020];
char b[200020];
int n, f=-2, g=-2;

int main()
{
    cin>>n;
    int k=0, ok=0;
    cin>>a>>b;
    for(int i=0; i<n; i++)
    {
        if(a[i]!=b[i])
        {
            if(ok==0 || ok==1)
            {
                if(is[a[i]][b[i]]!=0)
                {
                    ok=2, f=i, g=is[a[i]][b[i]]-1;
                    break;
                }
                is[b[i]][a[i]]=i+1;
            }
            if(ok!=1)
            {
                if(is1[a[i]]!=0)
                    ok=1, f=i, g=is1[a[i]]-1;
                else if(is2[b[i]]!=0)
                    ok=1, f=i, g=is2[b[i]]-1;

                is1[b[i]]=i+1;
                is2[a[i]]=i+1;
            }
        }
    }

    if(f>=0 && g>=0)
    {
    char aux=a[f];
    a[f]=a[g];
    a[g]=aux;
    }

    for(int i=0; i<n; i++)
    if(a[i]!=b[i])
        k++;

    cout<<k<<'\n';
    cout<<f+1<<' '<<g+1<<'\n';
    return 0;
}