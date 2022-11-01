#include <iostream>
#include <algorithm>
#include <bitset>
#include <vector>

typedef std::vector<std::bitset<100> > Players_type;

Players_type players;

bool all_is_well(Players_type::iterator it){
    for(Players_type::iterator ite = players.begin(); ite != players.end(); ++ite){
        if(it != ite && (~*it & *ite).none())
            return false;
    }
    return true;
}

int main(){
    int nplayer;
    std::cin >> nplayer;
    players.resize(nplayer);
    for(int i = 0; i < nplayer; i++){
        int ncard;
        std::cin >> ncard;
        while(ncard--){
            int card;
            std::cin >> card;
            players[i][card - 1] = true;
        }
    }
    for(Players_type::iterator it = players.begin(); it != players.end(); ++it){
        std::cout << (all_is_well(it) ? "YES" : "NO") << std::endl;
    }
}