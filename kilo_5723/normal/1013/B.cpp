#include<iostream>
#include<cstring>
using namespace std;
const int maxn=200005;
int a[maxn],exi[maxn];
bool exi2[maxn];
int main()
{
    memset(exi,0,sizeof(exi));
    memset(exi2,0,sizeof(exi2));
    int i,n,x;
    cin>>n>>x;
    for (i=0;i<n;i++){
        cin>>a[i];
        if (exi2[a[i]]){
            cout<<0;
            return 0;
        }
        exi2[a[i]]=true;
    }
    for (i=0;i<n;i++)
        if ((a[i]&x)==a[i]){
            switch (exi[a[i]&x]){
            case 0:
                exi[a[i]&x]=1;
                break;
            case 1:
                exi[a[i]&x]=2;
                break;
            case 3:
                exi[a[i]&x]=5;
                break;
            case 4:
                exi[a[i]&x]=5;
                break;
            case 5:
                exi[a[i]&x]=2;
                break;
            }
        }
        else
            switch (exi[a[i]&x]){
            case 0:
                exi[a[i]&x]=3;
                break;
            case 1:
                exi[a[i]&x]=5;
                break;
            case 3:
                exi[a[i]&x]=4;
                break;
            }
    for (i=0;i<maxn;i++)
        if (exi[i]==2){
            cout<<0;
            return 0;
        }
    for (i=0;i<maxn;i++)
        if (exi[i]==5){
            cout<<1;
            return 0;
        }
    for (i=0;i<maxn;i++)
        if (exi[i]==4){
            cout<<2;
            return 0;
        }
    cout<<-1;
    return 0;
}