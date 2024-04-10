from math import factorial as f

x = int(input())
#x, y = map(int, input().split())

print(f(x)//f(5)//f(x-5) + f(x)//f(6)//f(x-6) + f(x)//f(7)//f(x-7))