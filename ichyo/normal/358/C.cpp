#include <bits/stdc++.h>
#define REP(i,n) for(int i=0; i<(int)(n); ++i)

using namespace std;
typedef pair<int, int> P;

int main(){
    int N;
    cin >> N;
    vector<int> v(N);
    for(int i = 0; i < N; i++){
        cin >> v[i];
    }
    priority_queue<P> que;
    vector<bool> select(N);
    for(int i = 0; i < N; i++){
        if(v[i] == 0){
            for(int k = 0; k < 3 && que.size() > 0; k++){
                select[que.top().second] = true;
                que.pop();
            }
            que = priority_queue<P>();
        }else{
            que.push(P(v[i], i));
        }
    }

    int mode = 0;
    for(int i = 0; i < N; i++){
        if(select[i]){
            if(mode == 0){
                cout << "pushQueue" << endl;
            }else if(mode == 1){
                cout << "pushStack" << endl;
            }else if(mode == 2){
                cout << "pushFront" << endl;
            }else if(mode == 3){
                assert(false);
            }
            mode ++;
        }else if(v[i] == 0){
            cout << mode;
            if(mode >= 1) cout << " popQueue";
            if(mode >= 2) cout << " popStack";
            if(mode >= 3) cout << " popFront";
            cout << endl;
            mode = 0;
        }else{
            cout << "pushBack" << endl;
        }
    }
    return 0;
}