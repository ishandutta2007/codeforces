    #pragma GCC optimize("O3")
    #include <bits/stdc++.h>

//    #define int long long
    //#define double long double

    #define y0 y___0
    #define y1 y___1

    #define fi first
    #define se second
    #define pb push_back

    #define timer (clock()*1.0/CLOCKS_PER_SEC)
    #define e 0.000000000000000001

    using namespace std;

    #define MOD 1000000007
    int bpow(int a, int b)
    {
        if (b==0)
            return 1;
        if (b==1)
            return a;
        int x=bpow(a, b/2);
        int y=bpow(a, b%2);
        x*=x;
        x%=MOD;
        x*=y;
        x%=MOD;
        return x;
    }

    int a[100500];
    int n;
    map<int, int> s;
    vector<int> v;
    main()
    {
        ios_base::sync_with_stdio();
        cin.tie(0);
        cout.tie(0);

        int i1;
        cin>>n>>i1;
        int x;
        for (int i=1; i<=n; i++)
            cin>>x, s[x]++;
        i1*=8;
        i1/=n;
        for (auto pa:s)
            v.pb(pa.se);
        for (int i=1; i<v.size(); i++)
            v[i]+=v[i-1];
        int s2=1;
        for (int i=1; i<=i1; i++)
        {
            s2*=2;
            if (s2>=v.size())
                cout<<"0\n", exit(0);
        }
        int mx=v[s2-1];
        for (int i=0; i+s2<v.size(); i++)
            mx=max(mx, v[i+s2]-v[i]);
        cout<<n-mx<<"\n";
        return 0;
    }