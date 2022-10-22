#include<bits/stdc++.h>
using namespace std;


int main(){
    int t; cin >> t; long r, g, b, w; long r1, g1, b1, w1, temp;
    for(int o = 0; o < t; o++){
         cin >> r >> g >> b >> w;
         r1 = r % 2;
         g1 = g%2 ; b1 = b%2 ; w1 = w % 2;
         temp = g1 + b1 + r1 + w1;
          if(temp == 1 || temp == 0){
              cout << "Yes" << "\n";
              continue;
          }
         if(r == 0||g == 0|| b == 0){
              cout << "No" << "\n";
              continue;
         }
         w1 = 1 - w1;
            temp = 3 - g1 - b1 - r1 + w1;
            if(temp == 1 || temp == 0){
                cout << "Yes";
            }
            else{
                cout << "No";
            }
            cout << "\n";
    }
}