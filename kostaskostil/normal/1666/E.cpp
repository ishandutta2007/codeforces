#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

const int N=1e5+100;

int l,n;
int a[N];
int from[N],to[N];

bool check(int mn,int mx)
{
    a[n+1]=l;
    from[0]=to[0]=0;
    for(int i=1;i<=n;i++)
    {
        from[i]=max({from[i-1]+mn,a[i],a[i+1]-mx});
        to[i]=min(to[i-1]+mx,a[i+1]);
        if(from[i]>to[i])
            return false;
    }
    if(to[n]<l)
        return false;
    return true;
}

int ans[N];

void print(int mn,int mx)
{
    assert(check(mn,mx));
    ans[n]=l;
    ans[0]=0;
    for(int i=n-1;i>=1;i--)
        ans[i]=max(from[i],ans[i+1]-mx);
    for(int i=1;i<=n;i++)
        cout<<ans[i-1]<<" "<<ans[i]<<"\n";
    exit(0);
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>l>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
//    cout<<"   ";
//    for(int mx=1;mx<=l;mx++)
//        cout<<mx;
//    cout<<"\n";
//    for(int mn=1;mn<=l;mn++)
//    {
//        cout<<mn<<": ";
//        for(int mx=1;mx<=l;mx++)
//            if(mx<mn)
//                cout<<' ';
//            else if(check(mn,mx))
//                cout<<'+';
//            else
//                cout<<'-';
//        cout<<"\n";
//    }

//    while(true){
//        l=1000,n=10;
//        for(int i=1;i<=n;i++)
//            a[i]=rand()%(l+1);
//        sort(a+1,a+n+1);
//        int MN=l;
//        while(!check(MN,l))
//            MN--;
//        int MX=0;
//        while(!check(0,MX))
//            MX++;
//        for(int mn=0;mn<=l;mn++)
//        {
//            for(int mx=mn;mx<=l;mx++)
//                if(check(mn,mx)!=(mn<=MN&&MX<=mx))
//                    cout<<MN<<" "<<MX<<" | "<<mn<<" "<<mx<<endl,exit(0);
//        }
////        check(MN,MX);
////        print(MN,MX);
//    }

    int lo=0,hi=l;
    while(lo<hi)
    {
        int mi=(lo+hi+1)/2;
        if(check(mi,l))
            lo=mi;
        else
            hi=mi-1;
    }
    int mn=lo;

    lo=0,hi=l;
    while(lo<hi)
    {
        int mi=(lo+hi)/2;
        if(check(0,mi))
            hi=mi;
        else
            lo=mi+1;
    }
    int mx=lo;

    print(mn,mx);
}