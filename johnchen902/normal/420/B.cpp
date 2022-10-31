#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

constexpr unsigned maxn = 100000;
vector<pair<bool, unsigned>> vec;

bool never[maxn];   // never shown
bool start[maxn];   // must in room at start
bool last[maxn];    // must in room at start
bool entered[maxn]; // entered the room after start

int main(){
    unsigned n, m;
    scanf("%u %u", &n, &m);
    for(unsigned i = 0; i < m; i++){
        char c[2]; unsigned who;
        scanf("%1s %u", c, &who);
        vec.push_back({c[0] == '+', who - 1});
    }
    fill_n(never, n, true);
    for(const pair<bool, unsigned>& p: vec){
        never[p.second] = false;
        if(p.first){
            entered[p.second] = true;
            last[p.second] = true;
        } else {
            if(!entered[p.second])
                start[p.second] = true;
            last[p.second] = false;
        }
    }

    unsigned cnt = count(start, start + n, true);
    unsigned the_one = maxn+7;
    for(const pair<bool, unsigned>& p: vec){
        if(p.first){
            if(cnt == 0){
                // fprintf("is %u the one?\n", )
                if(the_one == maxn+7)
                    the_one = p.second;
                else if(the_one != p.second)
                    the_one = maxn+8;
            }
            cnt++;
        } else {
            cnt--;
            if(cnt == 0){
                if(the_one == maxn+7)
                    the_one = p.second;
                else if(the_one != p.second)
                    the_one = maxn+8;
            }
        }
    }
    // fprintf(stderr, "the_one %u\n", the_one);
    if(the_one < n){
        if(count(start, start + n, true) && !start[the_one]){
            the_one = maxn+9;
        } else if(count(last, last + n, true) && !last[the_one]){
            the_one = maxn+9;
        }
    }

    decltype (never)& proba = never;
    proba[the_one] = true;

    unsigned cnt2 = count(proba, proba + n, true);
    printf("%u\n", cnt2);
    if(cnt2 != 0){
        for(unsigned i = 0; i < n; i++) {
//            fprintf(stderr, "proba[%u]=%u\n", i, (unsigned)proba[i]);
            if(proba[i]){
                printf("%u%c", i + 1, --cnt2 ? ' ' : '\n');
            }
        }
    }
}