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
        for (int i=1; i<=n; i++)
            cin>>a[i];
        int l=2, r=n;
        int lt=a[1];
        bool al=false;
        int c=1;
        while (l<=r)
        {
            c++;
            if (!al)
            {
                int cur=0;
                while ((l<=r) and (cur<=lt))
                    cur+=a[r], r--;
                lt=cur;
            }
            else
            {
                int cur=0;
                while ((l<=r) and (cur<=lt))
                    cur+=a[l], l++;
                lt=cur;
            }
            al=!al;
        }
        int s1=0, s2=0;
        for (int i=1; i<l; i++)
            s1+=a[i];
        for (int i=r+1; i<=n; i++)
            s2+=a[i];
        cout<<c<<" "<<s1<<" "<<s2<<"\n";
    }

    return 0;
}