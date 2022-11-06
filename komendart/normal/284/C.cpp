#include <iostream>
#include <iomanip>
#include <vector>

#define I64 long long
#define endl '\n'

using namespace std;

int main()
{
ios_base::sync_with_stdio(false); cin.tie(0);

    I64 S = 0;
    vector<I64> numbers(1, 0);
    vector<I64> changes(1, 0);
    
    I64 n;
    cin >> n;

    numbers.reserve(n + 1);
    changes.reserve(n + 1);
    
    cout << setprecision(8);
    for(I64 i = 0; i < n; i += 1)
    {
        I64 t;
        cin >> t;
        
        if (t == 1)
        {
            I64 a, x;
            cin >> a >> x;
            
            S += a * x;
            changes[a - 1] += x;
        }
        else if (t == 2)
        {
            I64 k;
            cin >> k;
            
            S += k;
            numbers.push_back(k);
            changes.push_back(0);
        }
        else
        {
            S -= numbers.back() + changes.back();
            changes[changes.size() - 2] += changes[changes.size() - 1];
            numbers.pop_back();
            changes.pop_back();
        }
        
        cout << S / (double) numbers.size() << endl;
    }
    
    return 0;
}