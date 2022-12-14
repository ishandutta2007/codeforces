#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
const LL NS = 3*(1e5)+4;
LL N;
string arr[NS];
LL cnt[NS], can[NS], ans;
set < pair < LL, LL > > st;
set < pair < LL, LL > >::iterator p;
LL top;

void make(LL x){
    LL a = 0, b = 0, len = (LL)arr[x].size();
    top = 0;
    for(LL i=0;i<len;i++){
        if(arr[x][i]=='(') top++;
        else{
            if(top==0) a++;
            else top--;
        }
    }
    top = 0;
    for(LL i=len-1;i>=0;i--){
        if(arr[x][i]==')') top++;
        else{
            if(top==0) b++;
            else top--;
        }
    }
    if(!a||!b){
        can[x] = 1;
        if(a) cnt[x] = -a;
        else cnt[x] = b;
    }
}

int main(){
    ios_base::sync_with_stdio(false);

    cin >> N;
    for(LL i=0;i<N;i++) cin >> arr[i];
    for(LL i=0;i<N;i++) make(i);
    for(LL i=0;i<N;i++) if(can[i]){
        p = st.lower_bound(make_pair(cnt[i], 0));
        if(p!=st.end()&&p->first==cnt[i]){
            LL a = p->second;
            st.erase(p++), st.insert(make_pair(cnt[i], a+1));
        }
        else st.insert(make_pair(cnt[i], 1));
    }

    for(LL i=0;i<N;i++){
        if(can[i]){
            p = st.lower_bound(make_pair(cnt[i], 0));
            if(p->second>1){
                LL a = p->second;
                st.erase(p++), st.insert(make_pair(cnt[i], a-1));
            }
            else st.erase(p++);
            p = st.lower_bound(make_pair(-cnt[i], 0));
            if(p!=st.end()&&p->first==-cnt[i]){
                if(cnt[i]==0) ans += p->second*2;
                else ans += p->second;
            }
        }
    }
    for(LL i=0;i<N;i++) if(can[i]&&!cnt[i]) ans++;

    printf("%I64d", ans);

    return 0;
}