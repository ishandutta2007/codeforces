#include <iostream>
#include <string>
#include <map> 
#include <math.h>
#include <vector>
#include <algorithm>

using namespace std;

#define sqr(x) ((x)*(x))
#define PB(a) push_back(a)
#define MP(a) make_pair(a)

int n,m,k,p,ans,ci,cj;
string s;
bool f2[200000];
int a[10],b1[10],b2[10],a1[200000],a2[200000];

int main() {
#ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
#endif

        cin >> s;
        for (int i=0; i<s.length(); i++) {
                b1[s[i]-'0']++;
                b2[s[i]-'0']++;
        }

        for (int i=0; i<=b1[0]; i++) {
                b1[0]-=i; b2[0]-=i;
                for (int j=1; j<10; j++) {
                        int curans=i;
                        if (b1[j]>0 && b1[10-j]>0) curans++;
                        else continue;
                        b1[j]--; b2[10-j]--;
                        for (int k=0; k<10; k++) curans+=min(b1[k],b2[9-k]);
                        b1[j]++; b2[10-j]++;
                        if (curans>ans) {
                                ans=curans;
                                ci=i; cj=j;
                        }
                }
                b1[0]+=i; b2[0]+=i;
        }


        for (int i=s.length()-1; s.length()-i<=ci; i--) {
                a1[i]=a2[i]=0;
                b1[0]--; b2[0]--;
                f2[i]=true;
        }

        bool f=true;

        for (int i=s.length()-1; i>=0; i--) {
                if (f2[i]) continue;
                if (f) {
                        if (b1[cj]>0 && b1[10-cj]>0) {
                                a1[i]=cj; a2[i]=10-cj;
                                b1[cj]--; b2[10-cj]--;
                        } else {
                                for (int j=0; j<10; j++) if (b1[j]>0) {
                                        b1[j]--; a1[i]=j; break;
                                }
                                for (int j=0; j<10; j++) if (b2[j]>0) {
                                        b2[j]--; a2[i]=j; break;
                                }
                        }
                        f=false;
                } else {
                        bool f1=true;
                        for (int j=0; j<10; j++) {
                                if (b1[j] && b2[9-j]) {
                                        b1[j]--; b2[9-j]--;
                                        a1[i]=j; a2[i]=9-j;
                                        f1=false; break;
                                }
                        }
                        if (f1) {
                                for (int j=0; j<10; j++) if (b1[j]>0) {
                                        b1[j]--; a1[i]=j; break;
                                }
                                for (int j=0; j<10; j++) if (b2[j]>0) {
                                        b2[j]--; a2[i]=j; break;
                                }
                        }
                }
        }

        for (int i=0; i<s.length(); i++) cout << a1[i];
        cout << endl;
        for (int i=0; i<s.length(); i++) cout << a2[i];
        cout << endl;

        return 0;
}