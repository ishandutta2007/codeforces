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

ll numhas(string inp) {
    //cout << "numhas " << inp << endl;
    ll out = 0;
    for (int i = 0; i+3 < sz(inp); i++) {
        if (inp[i] == 'h' && inp[i+1] == 'a' && inp[i+2] == 'h' && inp[i+3] == 'a') out++;
    }
    return out;
}

string getPrefs(string inp) {
    string prefs;

    for (int i = 0; i < 3; i++) {
        prefs.pb(inp[i]);
    } 

    return prefs;
}

string getSuffs(string inp) {
    string suffs;

    for (int i = sz(inp) - 3; i < sz(inp); i++) {
        suffs.pb(inp[i]);
    } 

    return suffs;
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        map<string, string> smol;
        map<string, ll> numha;
        map<string, string> pref;
        map<string, string> suff;
        map<string, ll> len;


        int n;
        cin >> n;
        string lastname;
        while (n--) {
            string name;
            cin >> name;
            lastname = name;

            string cmd;
            cin >> cmd;

            if (cmd == ":=") {
                // All initial strings are smol
                string val;
                cin >> val;
                smol[name] = val;
                len[name] = sz(val);
                numha[name] = numhas(val);
            } else {
                // cmd == "="
                string op1, op2, garb;
                cin >> op1 >> garb >> op2;

                if (len[op1] <= 10 && len[op2] <= 10) {
                    // concat normally
                    string newstring = smol[op1] + smol[op2];
                    len[name] = sz(newstring);

                    if (sz(newstring) <= 10) {
                        // still smol
                        smol[name] = newstring;
                        numha[name] = numhas(newstring);
                    } else {
                        // BIG >:)
                        numha[name] = numhas(newstring);
                        
                        pref[name] = getPrefs(newstring);
                        suff[name] = getSuffs(newstring);
                    }
                } else if (len[op1] > 10 && len[op2] > 10) {
                    // both BIG
                    string intermed = suff[op1] + pref[op2];
                    numha[name] = numha[op1] + numha[op2] + numhas(intermed);
                    len[name] = len[op1] + len[op2];
                    pref[name] = pref[op1];
                    suff[name] = suff[op2];
                } else if (len[op1] <= 10 && len[op2] > 10) {
                    // first one smol, second one big
                    string intermed = smol[op1] + pref[op2];
                    numha[name] = numha[op2] + numhas(intermed);
                    len[name] = len[op1] + len[op2];
                    pref[name] = getPrefs(intermed);
                    suff[name] = suff[op2];
                } else if (len[op1] > 10 && len[op2] <= 10) {
                    string intermed = suff[op1] + smol[op2];
                    numha[name] = numha[op1] + numhas(intermed);
                    len[name] = len[op1] + len[op2];
                    pref[name] = pref[op1];
                    suff[name] = getSuffs(intermed);
                }
            }
            //cout << name << ' ' <<  numha[name] << ' ' << smol[name] << endl;
        }

        cout << numha[lastname] << endl;
    }
}