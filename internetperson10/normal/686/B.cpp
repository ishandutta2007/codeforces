#include <bits/stdc++.h>

using namespace std;

vector<int> animals;
vector<int> sorted;

int main() {
    int n, c, pos;
    cin >> n;
    for(int a=0; a<n; a++) {
        cin >> c;
        animals.push_back(c);
        sorted.push_back(c);
    }
    sort(sorted.begin(), sorted.end());
    for(int a=0; a<n; a++) {
        for(int b=a; b<n; b++) {
            if(animals[b]==sorted[a]) {
                pos = b;
                break;
            }
        }
        while(pos!=a) {
            pos--;
            printf("%d %d\n", pos+1, pos+2);
            int temp = animals[pos];
            animals[pos] = animals[pos+1];
            animals[pos+1] = temp;
        }
    }
}