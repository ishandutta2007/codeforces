#include <bits/stdc++.h>

#define fi first
#define se second
#define pb push_back

using namespace std;
const int nmax=5e5+100;
#define int long long

int a[nmax];
main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int ttt;
    cin>>ttt;
    for (int iii=0; iii<ttt; iii++){
        int n;
        cin>>n;
        if (n<=3)
            cout<<"-1\n";
        else
        {
            if (n%4==0)
                cout<<"2 4 1 3 ";
            if (n%4==1)
                cout<<"1 3 5 2 4 ";
            if (n%4==2)
                cout<<"2 4 1 5 3 6 ";
            if (n%4==3)
                cout<<"5 1 3 6 2 4 7 ";
            for (int i=1; i<=n/4 -1; i++)
            {
                int a=4*i + n%4;
                cout<<a+2<<" "<<a+4<<" "<<a+1<<" "<<a+3<<" ";
            }
            cout<<"\n";
        }
    }

    return 0;
}