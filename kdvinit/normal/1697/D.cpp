/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

char t1(int i)
{
    cout<<"? 1 "<<i<<endl;
    char x; cin>>x;
    return x;
}

int t2(int l, int r)
{
    cout<<"? 2 "<<l<<" "<<r<<endl;
    int x; cin>>x;
    return x;
}

void solve()
{
    int n;
    cin>>n;

    map<char, int> lst;
    vector<int> alc;

    char a[n+1];
    a[1]=t1(1);
    alc.push_back(a[1]);
    lst[a[1]]=1;

    int suf[n+1];
    for(int i=2; i<=n; i++)
    {
        suf[i]=0; set<char> st;
        for(int j=i-1; j>=1; j--)
        {
            st.insert(a[j]);
            suf[j]=st.size();
        }

        int y = t2(1, i);
        if(y>suf[1])
        {
            a[i]=t1(i);
            alc.push_back(a[i]);
            lst[a[i]]=i;
            continue;
        }

        int l=0;
        int r=alc.size();

        while(l+1!=r)
        {
            int mid = (l+r)/2;
            char z = alc[mid];
            int j = lst[z];

            int x = t2(j, i);
            if(x>suf[j]) r=mid;
            else l=mid;
        }

        a[i]=alc[l];
        lst[a[i]]=i;

        int pos=0;
        for(int j=0; j<alc.size(); j++) if(alc[j]==a[i]) pos=j;
        alc.erase(alc.begin()+pos);
        alc.push_back(a[i]);
    }

    cout<<"! ";
    for(int i=1; i<=n; i++) cout<<a[i];
    cout<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}