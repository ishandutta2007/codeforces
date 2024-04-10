#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
int log(int n) {
    if (n <= 2)
        return 1;
    return 1 + log((n + 1) / 2);
}
 
int power(int a, int b) {
    if (b == 0)
        return 1;
    return a * power(a, b - 1);
} 
 
void preprocess(vector<int> numbers, vector<int>& unique_numbers, vector<int>& counts) {
    int prev_value = -1;
    int count = 0;
    for (auto it = numbers.begin(); it != numbers.end(); ++it) {
        if (*it != prev_value) {
            if (prev_value >= 0) {
                unique_numbers.push_back(prev_value);
                counts.push_back(count);
            }
            prev_value = *it;
            count = 0;
        }
        count++;
    }
    
    if (prev_value >= 0) {
    unique_numbers.push_back(prev_value);
    counts.push_back(count);
    }
}
 
int main(void) {
    int n, I;
    cin >> n >> I;
    
    // find number of elements
    int bits = (8 * I) / n;
    if (bits > 20) {
        cout << 0;
        return 0;
    }
        
    int max_num = power(2, bits);
    
    vector<int> numbers(n);
    for (int i = 0; i < n; i++)
        cin >> numbers[i];
    
    sort(numbers.begin(), numbers.end());
    
    vector<int> unique_numbers, counts;
    
    preprocess(numbers, unique_numbers, counts);
    
    if (unique_numbers.size() <= max_num) {
        cout << 0;
        return 0;
    }
    
    int begin = 0, end = max_num;
    int count = 0;
    for (int i = begin; i < end; i++)
        count += counts[i];
        
    int best_count = count;
    while (end < counts.size()) {
        count = count + counts[end] - counts[begin];
        end++; begin++;
        if (count > best_count)
            best_count = count;
    }
    
    cout << n - best_count;
    return 0;
}