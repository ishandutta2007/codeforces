#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;
const int max_n = 300000;

typedef pair<int, int> Station;
typedef long long LongLong;

struct SortBySecond{
    bool operator()(const Station& s1, const Station& s2) const {
        return s1.second < s2.second;
    }
};

template<class InputIterator>
void printStations(InputIterator i_begin, InputIterator i_end){
    bool first = true;
    for(InputIterator it = i_begin; it != i_end; ++it){
        if(first)
            first = false;
        else
            cout << " ";
        cout << it->second;
    }
}

int main() {
    std::vector<Station> stations;
    int n; cin >> n;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        stations.push_back(Station(x, i + 1));
    }
    sort(stations.begin(), stations.end());
    int k; cin >> k;
    LongLong sum_position = 0, sum_distance = 0;
    for(int i = 0; i < k; i++){
        sum_distance += stations[i].first * (LongLong)i - sum_position;
        sum_position += stations[i].first;
    }
    int min_begin_id = 0, min_end_id = k;
    LongLong min_sum_distance = sum_distance;
    for(int begin_id = 0, end_id = k; end_id < n;){
        sum_position -= stations[begin_id].first;
        sum_distance -= sum_position - stations[begin_id].first * (LongLong)(k - 1);
        sum_distance += stations[end_id].first * (LongLong)(k - 1) - sum_position;
        sum_position += stations[end_id].first;
        begin_id++;
        end_id++;
        if(sum_distance < min_sum_distance){
            min_sum_distance = sum_distance;
            min_begin_id = begin_id;
            min_end_id = end_id;
        }
    }
    sort(stations.begin() + min_begin_id, stations.begin() + min_end_id, SortBySecond());
    printStations(stations.begin() + min_begin_id, stations.begin() + min_end_id);
    cout << endl;
    return 0;
}