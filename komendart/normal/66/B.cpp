#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    
    int result = 0, current_l = 0, next_l = 0;
    int previous_h = 0, is_up = 1;
    
    for (int i = 0; i < n; i += 1)
    {
        int h;
        cin >> h;
        
        if (is_up)
        {
            if (h < previous_h)
            {
                is_up = 0;
                next_l = 1;
            }
            current_l += 1;
        }
        else
        {
            if (h < previous_h)
            {
                current_l += 1;
                next_l = 1;
            }
            else if (h == previous_h)
            {
                current_l += 1;
                next_l += 1;
            }
            else
            {
                is_up = 1;
                current_l = next_l + 1;
            }
        }
        
        result = max(result, current_l);
        previous_h = h;
    }
    
    cout << result;
}