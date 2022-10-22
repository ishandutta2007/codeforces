#include <bits/stdc++.h> 
using namespace std; 
void count() 
{ 
    int len,c=0;
    cin >> len;
    int A[len];
    for (int i = 0; i < len; i++){
        cin >> A[i];
    }
    set<int> s; 
    for (int i = len - 1; i >= 0; i--) { 
        s.insert(A[i]); 
        auto it = s.lower_bound(A[i]); 
        c += (distance(s.begin(), it) > 0); 
    } 
    cout << c << endl;
} 
  
// Driver code 
int main() 
{ 
    int q;
    cin >> q;
    while (q){
        q--;
        count();     
    }
    
    return 0; 
}