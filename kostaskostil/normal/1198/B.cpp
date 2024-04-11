    #pragma GCC optimize("O3")
    #include <bits/stdc++.h>

    #define int long long
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

    int a[200500];
    int t[200500];
    int tx[200500];
    int n, q;


    main()
    {
        ios_base::sync_with_stdio();
        cin.tie(0);
        cout.tie(0);

        cin>>n;
        for (int i=1; i<=n; i++)
            cin>>a[i];
        cin>>q;
        for (int i=1; i<=q; i++)
        {
            int x;
            cin>>x;
            if (x==1)
            {
                int y, z;
                cin>>y>>z;
                a[y]=z;
                t[y]=i;
            }
            if (x==2)
            {
                int y;
                cin>>y;
                tx[i]=y;
            }
        }
        for (int i=q-1; i>=1; i--)
            tx[i]=max(tx[i], tx[i+1]);
        tx[0]=tx[1];
        for (int i=1; i<=n; i++)
        {
            cout<<max(a[i], tx[t[i]])<<" ";
        }
        return 0;
    }