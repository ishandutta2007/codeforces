            #include <bits/stdc++.h>
             
            using namespace std;
             
            int main() {
                ios::sync_with_stdio(false);
                cin.tie(0);
                int t;
                cin >> t;
                while(t--) {
                    long long int p, q, b;
                    cin >> p >> q >> b;
                    long long int gcf = __gcd(p, q);
                    p/=gcf;
                    q/=gcf;
                    gcf = __gcd(q, b);
                    while(gcf!=1) {
                        gcf = __gcd(q, b);
                        while((q % gcf) == 0 && gcf > 1) q /= gcf;
                        //cout << q << ' ' << gcf << endl;
                    }
                    if(q==1) cout << "Finite\n";
                    else cout << "Infinite\n";
                }
            }