#include <iostream>
#include <string>
#include <map>
#include <set>

int main(int argc, char** argv)
{
	std::map<std::string, std::string> color_to_name;
	std::set<std::string> color_found;
	int m;

	color_to_name["purple"] = "Power";
	color_to_name["green"]  = "Time";
	color_to_name["blue"]   = "Space";
	color_to_name["orange"] = "Soul";
	color_to_name["red"]    = "Reality";
	color_to_name["yellow"] = "Mind";

	std::cin >> m;

	for(int i = 0; i < m; ++i)
	{
		std::string col;
		std::cin >> col;

		color_found.insert(col);
	}

	std::cout << 6 - m << std::endl;

	for(std::map<std::string, std::string>::map::iterator it = color_to_name.begin();
		it != color_to_name.end();
		it++)
	{
		std::string col = it->first;
		std::string nam = it->second;

		if(color_found.find(col) == color_found.end())
			std::cout << nam << std::endl;
	}

	return 0;
}