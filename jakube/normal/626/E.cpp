#include <bits/stdc++.h>

using namespace std;

#define ALL(v) v.begin(),v.end()
#define FOR(I, N) for (int I = 0; I < (N); ++I)
#define FORR(I, A, B) for (int I = (A); I < (B); ++I)

const double EPS = 1e-4;
const long double PI = acos((long double)-1.0);
const long long int MOD = 1e9 + 7;

typedef long long int lint;
typedef long double ld;
lint powmod(lint a,lint b, lint mod) {lint res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}

const int debug = 1;
template <typename T>
void DBG(vector<T> v){if(debug){for(T t:v)cout<<t<<"  ";cout<<endl;}}
template <typename T>
void DBG(T t){if(debug)cout<<t<<endl;}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie (NULL);
    cout.precision(10);
    cout << fixed;


    int n;
    cin >> n;
    vector<int> v(n);
    FOR(i, n)
        cin >> v[i];

    sort(ALL(v));

    vector<lint> psum(n);
    lint sum = 0;
    FOR(i, n)
    {
        sum += v[i];
        psum[i] = sum;
    }


    double best = 0;
    int best_idx = 0;
    int best_j = 0;

    for (int mean_idx = 0; mean_idx < n; mean_idx++)
    {
        int m = min(mean_idx, n - mean_idx - 1);
        int left = 0;
        int right = m;

        double vd = v[mean_idx];

        while (left != right)
        {
            int middle = (left + right) / 2;
            lint value = psum[n-1] - psum[n - middle - 1];
            value += psum[mean_idx] - (mean_idx - middle - 1 >= 0 ? psum[mean_idx - middle - 1] : 0);
            vd = (double)value / double(2*middle + 1);
            if (middle < right)
            {
                lint value_r = psum[n-1] - psum[n - middle - 1 - 1];
                value_r += psum[mean_idx] - (mean_idx - middle - 1 - 1 >= 0 ? psum[mean_idx - middle - 1 - 1] : 0);
                double vdr = (double)value_r / (double)(2*middle+3);

                if (vd < vdr)
                {
                    left = middle + 1;
                }
                else
                {
                    right = middle;
                }
            }
            else
            {
                lint value_l = psum[n-1] - psum[n - middle + 1 - 1];
                value_l += psum[mean_idx] - (mean_idx - middle + 1 - 1 >= 0 ? psum[mean_idx - middle + 1 - 1] : 0);
                double vdl = (double)value_l / (double)(2*middle-1);

                if (vdl < vd)
                {
                    left = middle + 1;
                }
                else
                {
                    right = middle;
                }
            }
        }


        lint val = psum[n-1] - psum[n - left - 1];
        val += psum[mean_idx] - (mean_idx - left - 1 >= 0 ? psum[mean_idx - left - 1] : 0);
        vd = (double)val / double(2*left + 1);

        double diff = vd - v[mean_idx];
        if (diff > best)
        {
            best = diff;
            best_idx = mean_idx;
            best_j = left;
        }
    }
    
    vector<int> output;
    for (int i = best_idx - best_j; i <= best_idx; i++)
    {
        output.push_back(v[i]);
    }
    for (int i = n - best_j; i < n; i++)
    {
        output.push_back(v[i]);
    }

    cout << 2*best_j+1 << endl;
    DBG(output);
}