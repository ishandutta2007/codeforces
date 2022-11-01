NUM = int(input())
for T in range(0,NUM):
    n = int(input())
    print(n // 3 + (n % 3 == 1) , n // 3 + (n % 3 == 2))