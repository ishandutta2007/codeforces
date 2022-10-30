#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define files1 freopen("input.txt","r",stdin)
#define files2 freopen("output.txt","w",stdout)
#define mp make_pair
#define fast_io ios_base::sync_with_stdio(0);
#define forn() for(int i=0;i<n;i++)
#define pii pair<int,int>
#define int long long
using namespace std;

const int inf=2e9;
const double eps=1e-9;
const int maxn = 2e5+500, base = 1e9+7,maxm= 1e4+5;

vector<int> prefix_function (vector<pair<int,char> > s) {
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
int n ,m;
string s,t;

vector<pair<int,char> > st,st1;

string from_int(int x)
{
    string ans;
    while (x)
    {
        ans.pb(x%10 + '0');
        x /= 10;
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

void print(vector<pair<int,char> > a)
{
    for (int i=0;i<a.size();i++)
        cerr<<a[i].f<<' '<<a[i].s<<endl;

}
 main()
{
    fast_io;
    //files1;
    cin >> n >> m;
    for (int i=0;i<n;i++){
        string s1;
        cin >> s1;
        int len = 0;
        int j;
        for (j=0;s1[j]!='-';j++){
            len*=10;
            len+=(int)(s1[j]-'0');
        }
        while (!st.empty() && st.back().s == s1[j+1]){
            len += st.back().f;
            st.pop_back();
        }
        st.pb(mp(len,s1[j+1]));
    }

    pair<int,char> b, e;
    for (int i=0;i<m;i++){
        string s1;
        cin >> s1;
        int len = 0;
        int j;
        for (j=0;s1[j]!='-';j++){
            len*=10;
            len+=(int)(s1[j]-'0');
        }
        while (!st1.empty() && st1.back().s == s1[j+1]){
            len += st1.back().f;
            st1.pop_back();
        }
        st1.pb(mp(len,s1[j+1]));
    }

    if (st1.size() == 1){
            int ans = 0;
        for (int i=0;i<st.size();i++){
            if (st[i].s == st1.front().s && st[i].f >= st1.front().f)
            ans+=(st[i].f - st1[0].f + 1);
        }

        cout<<ans;
        return 0;
    }
    int sz = st1.size();
    b = st1.front();
    st1.erase(st1.begin());
    e = st1.back();
    st1.pop_back();

    vector<pair<int,char> > got;
    for (int i=0;i<st1.size();i++)
        got.pb(st1[i]);
    got.pb(mp(-1,'%'));
    for (int i=0;i<st.size();i++)
        got.pb(st[i]);

    vector<int> p = prefix_function(got);

   // print(st);
    //for (int i=0;i<p.size();i++)
    //    cerr<<p[i]<<' ';

    int ans = 0;
    for (int i = 0 ; i< p.size();i++){
        if (i + sz - 1 < p.size() && p[i + sz - 1] == sz - 2){
            if (i+1 < st.size() && st[i+1].s == e.s && st[i+1].f >= e.f)
            {
                int front = i -sz + 2;
                if (front >= 0 && st[front].s == b.s && st[front].f >= b.f)
                    ans++;
            }
        }
    }

    cout<<ans;
    return 0;
}