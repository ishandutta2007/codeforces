#include <bits/stdc++.h>

using namespace std;
#define DIM2 507
#define DIM 100007

#define INF 10E18
#define MAXN 10007
typedef pair<long long,long long> pairll;
struct troinik{
    long long b,w,t;
};
long long t,n,res1,res2;
string str;
vector<char> ch;
int main() {
    //freopen("input.txt","r",stdin);
    cin>>t;
    for (int h = 1;h<=t;h++){
        long long res = 0;
        cin>>n;
        ch.resize(n);
        cin>>str;
        res1 = 0;
        res2 = 0;
        for (int i = 0;i<n;i++){


            if (str[i]=='>'){
                    break;
            }
            res1++;
        }
        for (int i = n-1;i>=0;i--){

            if (str[i]=='<'){
                break;
            }
            res2++;
        }

        cout<<min(res1,res2)<<endl;
        //printf("%lld\n",ch.size());
    }
}