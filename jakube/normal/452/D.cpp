#include <bits/stdc++.h>

using namespace std;

int main(){
    int k, n1, n2, n3, t1, t2, t3;
    cin >> k >> n1 >> n2 >> n3 >> t1 >> t2 >> t3;
    
    vector<int> finish_time_w(n1, 0);
    vector<int> finish_time_d(n2, 0);
    vector<int> finish_time_f(n3, 0);

    for(int i = 0; i < k; i++){
        finish_time_w[i%n1] = finish_time_w[i%n1] + t1;
        finish_time_d[i%n2] = max(finish_time_d[i%n2], finish_time_w[i%n1]) + t2;
        finish_time_f[i%n3] = max(finish_time_f[i%n3], finish_time_d[i%n2]) + t3;
    }
    cout << *max_element(finish_time_f.begin(), finish_time_f.end()) << endl;
}