#include <iostream>
#include <algorithm>
#include <cstdint>

using namespace std;

int main() {
    int64_t n; cin >> n;
    const int64_t undecided = 999999999999ul;
    int64_t last = undecided;
    int64_t diff = undecided;
    int64_t unkn1 = 0;
    int64_t unkn2 = 0;
    int64_t coun = 0;
    while(n--){
        int64_t a; cin >> a;
        if(last == undecided){
            if(a == -1)
                unkn1++;
            else
                last = a;
        }else if(diff == undecided){
            if(a == -1)
                unkn2++;
            else {
                if((a - last) % (unkn2 + 1) == 0){
                    diff = (a - last) / (unkn2 + 1);
                    if(last - diff * unkn1 >= 1){
                        last = a;
                        unkn1 = unkn2 = 0;
                    } else {
                        diff = undecided;
                        last = a;
                        unkn1 = unkn2 = 0;
                        coun++;
                    }
                } else {
                    last = a;
                    unkn1 = unkn2 = 0;
                    coun++;
                }
            }
        }else{
            if(a == -1){
                if(last + diff >= 1){
                    last += diff;
                } else {
                    unkn1 = 1;
                    last = diff = undecided;
                    coun++;
                }
            } else {
                if(last + diff == a){
                    last = a;
                } else {
                    last = a;
                    diff = undecided;
                    coun++;
                }
            }
        }

//        cerr << last << " " << diff << " " << unkn1 << " " << unkn2 << endl;
    }
    if(last != -1 || unkn1 != 0 || unkn2 != 0)
        coun++;
    cout << coun << endl;
}