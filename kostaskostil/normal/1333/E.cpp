#include <bits/stdc++.h>

#define fi first
#define se second
#define pb push_back

#define int long long

using namespace std;

int n;
int mover_queen(vector<vector<int> >& brd)
{
    vector<set<pair<int, pair<int, int> > > > x(n), y(n), sum(2*n), dif(2*n);
    set<pair<int, pair<int, int> > > all;
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
    {
        int v=brd[i][j];
        x[i].insert({v, {i, j}});
        y[j].insert({v, {i, j}});
        sum[i+j].insert({v, {i, j}});
        dif[n+i-j].insert({v, {i, j}});
        all.insert({v, {i, j}});
    }
    int cx=-1, cy=-1;
    int ans=-1;
    for (int i=0; i<n*n; i++)
    {
        if ((cx==-1) or (
            x[cx].empty() and y[cy].empty() and sum[cx+cy].empty() and dif[n+cx-cy].empty()
            ))
        {
            ans++;
            auto it=*all.begin();
            cx=it.se.fi;
            cy=it.se.se;
        }
        else
        {
            pair<int, pair<int, int> > pa={1e9, {0, 0}};
            if (!x[cx].empty()) pa=min(pa, *x[cx].begin());
            if (!y[cy].empty()) pa=min(pa, *y[cy].begin());
            if (!sum[cx+cy].empty()) pa=min(pa, *sum[cx+cy].begin());
            if (!dif[n+cx-cy].empty()) pa=min(pa, *dif[n+cx-cy].begin());
            cx=pa.se.fi;
            cy=pa.se.se;
        }
        int v=brd[cx][cy];
        x[cx].erase({v, {cx, cy}});
        y[cy].erase({v, {cx, cy}});
        sum[cx+cy].erase({v, {cx, cy}});
        dif[n+cx-cy].erase({v, {cx, cy}});
        all.erase({v, {cx, cy}});

//        cout<<cx<<" "<<cy<<"\n";
    }
    return ans;
}
int mover_rook(vector<vector<int> >& brd)
{
    vector<set<pair<int, pair<int, int> > > > x(n), y(n);
    set<pair<int, pair<int, int> > > all;
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
    {
        int v=brd[i][j];
        x[i].insert({v, {i, j}});
        y[j].insert({v, {i, j}});
        all.insert({v, {i, j}});
    }
    int cx=-1, cy=-1;
    int ans=-1;
    for (int i=0; i<n*n; i++)
    {
        if ((cx==-1) or (
            x[cx].empty() and y[cy].empty()
            ))
        {
            ans++;
            auto it=*all.begin();
            cx=it.se.fi;
            cy=it.se.se;
        }
        else
        {
            pair<int, pair<int, int> > pa={1e9, {0, 0}};
            if (!x[cx].empty()) pa=min(pa, *x[cx].begin());
            if (!y[cy].empty()) pa=min(pa, *y[cy].begin());
            cx=pa.se.fi;
            cy=pa.se.se;
        }
        int v=brd[cx][cy];
        x[cx].erase({v, {cx, cy}});
        y[cy].erase({v, {cx, cy}});
        all.erase({v, {cx, cy}});

//        cout<<cx<<" "<<cy<<"\n";
    }
    return ans;
}

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
//    vector<vector<int> > v(n, vector<int>(n));
//    for (int i=0; i<n; i++)
//        for (int j=0; j<n; j++)
//            cin>>v[i][j];
//    cout<<mover_queen(v)<<"\n";
//    cout<<mover_rook(v)<<"\n";

///    

//    while (clock()*1.0/CLOCKS_PER_SEC < 0.8)
//    {
//        vector<vector<int> > v(n, vector<int>(n));
//        vector<int> p(n*n);
//        for (int i=0; i<n*n; i++)
//            p[i]=i;
//        random_shuffle(p.begin(), p.end());
//        for (int i=0; i<n; i++)
//            for (int j=0; j<n; j++)
//                v[i][j]=p[n*i+j]+1;
//        if (mover_rook(v)<mover_queen(v))
//        {
//            for (int i=0; i<n; i++, cout<<"\n")
//                for (int j=0; j<n; j++)
//                    cout<<v[i][j]<<" ";
//            exit(0);
//        }
//    }
//    cout<<"-1\n";

    vector<vector<int> > v1={{13,  9, 10, 1},
                             {14, 12, 16, 2},
                             {15,  8, 11, 3},
                             { 6,  7,  5, 4}};
    if (n<3)
        cout<<"-1\n";
    else if (n==3){
        for (int i=0; i<3; i++, cout<<"\n")
            for (int j=0; j<3; j++)
            cout<<v1[i][j]-7<<" ";
    }
    else{
        vector<int> pr(n);
        pr[1]=0;
        for (int i=1; i<n-1; i++)
            pr[i+1]=pr[i]+2*n-2*i+1;

        for (int i=0; i<n; i++, cout<<"\n")
            for (int j=0; j<n; j++)
        {
            if (i<4 and j<4)
            {
                if (n%2==1)
                cout<<n*n-16+v1[i][j]<<" ";
                else
                cout<<n*n-16+v1[j][i]<<" ";
            }
            else
            {
                int l=min(n-i, n-j);
                if (l<n-3)
                {
                    int s=pr[l];
                    if ((i+l==n) and (l%2==1)) cout<<s+1+j<<" "; else
                    if ((i+l==n) and (l%2==0)) cout<<s+(2*n-2*l+1-j)<<" "; else
                    if ((j+l==n) and (l%2==1)) cout<<s+1+(2*n-2*l-i)<<" "; else
                    if ((j+l==n) and (l%2==0)) cout<<s+1+i<<" ";
                }
            }
        }

    }
}