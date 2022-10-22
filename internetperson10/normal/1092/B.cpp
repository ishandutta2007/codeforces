#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int skill_level[101];

int main() {
    int students, sum=0;
    cin >> students;
    for(int a=0; a<students; a++) {
        cin >> skill_level[a];
    }
    sort(skill_level+0, skill_level+students);
    for(int a=0; a<students; a+=2) {
        sum+=abs(skill_level[a]-skill_level[a+1]);
    }
    cout << sum;
}