n = int(input())
number_of_ways = (27**n - 7**n) % (10**9 + 7)
print(number_of_ways)