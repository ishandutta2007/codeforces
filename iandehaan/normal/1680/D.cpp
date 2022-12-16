#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define pb push_back
#define mp make_pair

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    ll k;
    cin >> n >> k;
    ll a[n];
    ll sma = 0;
    ll numzeroes = 0;
    rep(i, 0, n) {
        cin >> a[i];
        sma += a[i];
        if (a[i] == 0) numzeroes++;
    }
    ll requiredsm = -1*sma;

    if ((abs(requiredsm)+(k-1))/k > numzeroes) {
        cout << -1 << endl;
        return 0;
    }

    ll out = 0;

    for (int switchind = 0; switchind <= n; switchind++) {
        // try to go as high as possible before switchind
        // try to go as low as possible after switchind
        // then do the other way

        // first high as possible
        {
        
        ll mxheight = 0;
        ll mnheight = 0;
        ll currpos = 0;
        ll smrem = sma;
        ll zeroesleft = numzeroes;
        for (int ind = 0; ind < n; ind++) {
            if (a[ind] == 0) {
                zeroesleft--;
                if (ind < switchind) {
                    // try to go as high as possible
                    ll wiggleroom = k*zeroesleft;
                    // can only let currpos + smrem go up to wiggleroom
                    ll canmove = wiggleroom - (currpos + smrem);
                    ll moveamt = min(canmove, k);
                    currpos += moveamt;
                } else {
                    // try to go as low as possible
                    ll wiggleroom = -1*k*zeroesleft;
                    // can only let currpos + smrem go down to wiggleroom
                    ll canmove = wiggleroom - (currpos + smrem);
                    ll moveamt = max(canmove, -1*k);
                    currpos += moveamt;
                }   
            } else {
                currpos += a[ind];
                smrem -= a[ind];
                
            }
            mxheight = max(mxheight, currpos);
            mnheight = min(mnheight, currpos);
        }

        //cout << mxheight << ' ' << mnheight << endl;

        out = max(out, mxheight-mnheight+1);

        }

        {
        
        ll mxheight = 0;
        ll mnheight = 0;
        ll currpos = 0;
        ll smrem = sma;
        ll zeroesleft = numzeroes;
        for (int ind = 0; ind < n; ind++) {
            if (a[ind] == 0) {
                zeroesleft--;
                if (ind < switchind) {
                    // try to go as low as possible
                    ll wiggleroom = -1*k*zeroesleft;
                    // can only let currpos + smrem go down to wiggleroom
                    ll canmove = wiggleroom - (currpos + smrem);
                    ll moveamt = max(canmove, -1*k);
                    currpos += moveamt;
                } else {
                    // try to go as high as possible
                    ll wiggleroom = k*zeroesleft;
                    // can only let currpos + smrem go down to wiggleroom
                    ll canmove = wiggleroom - (currpos + smrem);
                    ll moveamt = min(canmove, k);
                    currpos += moveamt;
                }   
            } else {
                currpos += a[ind];
                smrem -= a[ind];
                
            }
            mxheight = max(mxheight, currpos);
            mnheight = min(mnheight, currpos);
        }
        

        out = max(out, mxheight-mnheight+1);

        }
    }

    cout << out << endl;


}