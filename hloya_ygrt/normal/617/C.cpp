#include <bits/stdc++.h>

using namespace std;
#define pb push_back
#define mp make_pair
#define f first
#define s second


const int inf = 2e9;

const int maxn = 3000;

#define int long long
    int ans = 2000000000000001LL;

int dist ( int x1, int y1, int x2, int y2 ) {
    return (x1-x2) * (x1-x2) + (y1-y2) *(y1-y2);
}

pair < int, int > dots[maxn];
bool tryed[maxn];

void _try(int i,int r1,int x1,int y1){
    if ( dist(dots[i].f,dots[i].s,x1,y1 )<=r1 )
        tryed[i] = true;
    else
        tryed[i] = false;
}

 main()
{

    int n, x1, x2, y1, y2;

    cin>>n>>x1>>y1>>x2>>y2;
    for (int i=0;i<n;i++) {
        cin>>
        dots[i].f>>
        dots[i].s;
}

    int r1 = 0;
    for (int j=0;j<=n;j++) {
        
         int r2 = 0;
        
        bool last = 0;
        if (j==n)
            last=1;
       
        for (int i=0; i<n;i++)
               _try(i,r1,x1,y1);

        for (int i=0;i<n;i++)
            if ( !tryed[i] )
                r2 = max(r2,dist(dots[i].f,dots[i].s, x2, y2 ));

        ans = min( ans, r1+r2 );

        if (!last)
            r1 = dist(dots[j].f,dots[j].s,x1,y1);
}
    cout << ans;
    return 0;
}