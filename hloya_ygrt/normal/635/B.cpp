#include <bits/stdc++.h>

#define f first
#define s second
#define ll long long
#define pb push_back
#define pf push_front
#define files1 freopen("input.txt","r",stdin)
#define files2 freopen("output1.txt","w",stdout)
#define mp make_pair
#define fast_io ios_base::sync_with_stdio(0);
#define forn() for(int i=0;i<n;i++)

using namespace std;

const int inf=2e9;
const double eps=1e-9;
const int maxn = 2e5+5, base = 1e9+7,maxm= 1e4+5;


vector<int> prefix_function (vector<int> & s) {
	int n = (int) s.size();
	vector<int> pi (n);
	for (int i=1; i<n; ++i) {
		int j = pi[i-1];
		while (j > 0 && s[i] != s[j])
			j = pi[j-1];
		if (s[i] == s[j])  ++j;
		pi[i] = j;
	}
	return pi;
}

    vector<int> sk;
        int s[maxn] , s1[maxn];

int main()
{
    //files1;
    //files2;
    int n;
    scanf("%d",&n);
    for (int i=0;i<n-1;i++){
        int x;
        scanf("%d",&x);
        s[i] = x;
        if (x == 0)
            i--;
    }


    for (int i=0;i<n-1;i++){
        int x;
        scanf("%d",&x);
        s1[i] = x;
        if (x == 0)
            i--;

    }
    for (int i=0;i<n-1;i++){
        sk.pb(s1[i]);
    }

    for (int i=0;i<n-1;i++){
        sk.pb(s[i]);
    }

    for (int i=0;i<n-1;i++){
        sk.pb(s[i]);
    }

    //for (int i=0;i<sk.size();i++)
    //    cout<<sk[i]<<' ';

    vector<int> p = prefix_function(sk);

    for (int i=0;i<p.size();i++)
        if (p[i] == n - 1)
    {
        cout<<"Yes";
        exit(0);
    }
    cout<<"No";
    return 0;
}