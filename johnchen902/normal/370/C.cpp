#include <iostream>
#include <algorithm>
#include <utility>

const int max_m = 100;

int n, m;
std::pair<int, int> left_hand[max_m]; // (count, glove_id)
std::pair<int, int> right_hand[max_m]; // (count, glove_id)

int main(){
    std::cin >> n >> m;
    for(int i = 0; i < m; i++){
        left_hand[i].second = i + 1;
    }
    for(int i = 0; i < n; i++){
        int glove;
        std::cin >> glove;
        left_hand[glove - 1].first++;
    }
    std::sort(left_hand, left_hand + m, std::greater<std::pair<int, int> >());
    if(left_hand[0].first > n / 2){
        std::cout << 2 * (n - left_hand[0].first) << std::endl;
        while(left_hand[0].first > n / 2){
            std::cout << left_hand[0].second << " " << left_hand[0].second << std::endl;
            n--;
            left_hand[0].first--;
        }
    } else {
        std::cout << n << std::endl;
    }
    std::rotate_copy(left_hand, left_hand + 1, left_hand + m, right_hand);
    std::pair<int, int> *pl = left_hand, *pr = right_hand;
    while(n){
        while(pl->first == 0)
            pl++;
        while(pr->first == 0)
            pr++;
        std::cout << pl->second << " " << pr->second << std::endl;
        pl->first--;
        pr->first--;
        n--;
    }
}