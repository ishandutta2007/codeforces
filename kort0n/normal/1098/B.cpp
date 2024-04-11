#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> i_i;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
string ATGC = "ATGC";
int row[300001][4][2];
int column[300001][4][2];
//vector<int[4][2]> row;
//vector<int[4][2]> column;
int initial[5];
int result[5];
string field[300001];
bool same(){
    for(int i = 0; i < 4; i++){
        for(int j = i + 1; j < 4; j++){
            if(initial[i] == initial[j]) return true;
        }
    }
    return false;
}

void add(int index){
    initial[index]++;
    if(initial[index] == 4){
        initial[index] = 0;
        add(index + 1);
    }
}

int main() {
    //cout.precision(10);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> field[i];
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            for(int moji = 0; moji < 4; moji++){
                if(ATGC[moji] == field[i][j]) continue;
                row[i][moji][j % 2]++;
                column[j][moji][i % 2]++;
            }
        }
    }
    for(int i = 0; i < 5; i++){
        initial[i] = 0;
    }
    int ans = 300000;
    vector<i_i> ANS(300000);
    bool checker;
    //vector<int> row_ans;
    //vector<int> column_ans;
    while(true){
        add(0);
        while(same()){
            add(0);
        }
        if(initial[4] != 0) break;
        /*for(int i = 0; i < 4; i++){
            cout << initial[i] << " ";
        }
        cout << endl;*/
        int now1 = 0;
        vector<i_i> NOW(300000);
        for(int i = 0; i < n; i += 2){
            if(row[i][initial[0]][0] + row[i][initial[1]][1] < row[i][initial[1]][0] + row[i][initial[0]][1]){
                NOW[i] = {initial[0], initial[1]};
            } else {
                NOW[i] = {initial[1], initial[0]};
            }
            now1 += min(row[i][initial[0]][0] + row[i][initial[1]][1], row[i][initial[1]][0] + row[i][initial[0]][1]);
        }
        for(int i = 1; i < n; i += 2){
            if(row[i][initial[2]][0] + row[i][initial[3]][1] < row[i][initial[3]][0] + row[i][initial[2]][1]){
                NOW[i] = {initial[2], initial[3]};
            } else {
                NOW[i] = {initial[3], initial[2]};
            }
            now1 += min(row[i][initial[2]][0] + row[i][initial[3]][1], row[i][initial[3]][0] + row[i][initial[2]][1]);
        }
        if(now1 < ans){
            swap(NOW, ANS);
            checker = true;
        }
        ans = min(ans, now1);
        int now2 = 0;
        for(int i = 0; i < m; i += 2){
            if(column[i][initial[0]][0] + column[i][initial[2]][1] < column[i][initial[2]][0] + column[i][initial[0]][1]){
                NOW[i] = {initial[0], initial[2]};
            } else {
                NOW[i] = {initial[2], initial[0]};
            }
            now2 += min(column[i][initial[0]][0] + column[i][initial[2]][1], column[i][initial[2]][0] + column[i][initial[0]][1]);
        }
        for(int i = 1; i < m; i += 2){
            if(column[i][initial[1]][0] + column[i][initial[3]][1] < column[i][initial[3]][0] + column[i][initial[1]][1]){
                NOW[i] = {initial[1], initial[3]};
            } else {
                NOW[i] = {initial[3], initial[1]};
            }
            now2 += min(column[i][initial[1]][0] + column[i][initial[3]][1], column[i][initial[3]][0] + column[i][initial[1]][1]);
        }
        if(now2 < ans){
            checker = false;
            swap(NOW, ANS);
        }
        ans = min(ans, now2);
        //cout << ans << " " << ANS[0].first << " " << ANS[1].first << " " << ANS[0].second << " " << ANS[1].second << " " << endl;
    }
    if(checker){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if((j % 2) == 0){
                    cout << ATGC[ANS[i].first];
                } else {
                    cout << ATGC[ANS[i].second];
                }
            }
            cout << endl;
        }
    } else {
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(i % 2 == 0){
                    cout << ATGC[ANS[j].first];
                } else {
                    cout << ATGC[ANS[j].second];
                }
            }
            cout << endl;
        }
    }
    return 0;
}