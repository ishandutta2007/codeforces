// Hydro submission #62cd07bb4125dc528b1ce1b4@1657604027818
#include <iostream>
#include <string>

int main(){
    std::string borze;
    std::cin >> borze;

    int i = 0;
    while(i < borze.length()){
        if(borze[i] == '.'){
            std::cout << 0;
            i++;
        } else {
            if (borze[i+1] == '.'){
                std::cout << 1;
            } else {
                std::cout << 2;
            }
            i +=2;
        }
    }
}