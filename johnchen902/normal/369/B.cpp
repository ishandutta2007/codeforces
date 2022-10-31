#include <iostream>
#include <algorithm>

void print(int i){
    static bool first = true;
    if(first)
        first = false;
    else
        std::cout << " ";
    std::cout << i;
}

void print_n(int i, int n){
    while(n--)
        print(i);
}

int main(){
    int students, top_k, least, most, sum_all, sum_top_k;
    std::cin >> students >> top_k >> least >> most >> sum_all >> sum_top_k;
    print_n(sum_top_k / top_k + 1, sum_top_k % top_k);
    print_n(sum_top_k / top_k, top_k - sum_top_k % top_k);
    int bottom_k = students - top_k, sum_bottom_k = sum_all - sum_top_k;
    if(bottom_k){
        print_n(sum_bottom_k / bottom_k + 1, sum_bottom_k % bottom_k);
        print_n(sum_bottom_k / bottom_k, bottom_k - sum_bottom_k % bottom_k);
    }
    std::cout << std::endl;
}