a, b, c, d, e = map(int, input())
n = a*10000 + c*1000 + e*100 + d*10 + b
print(str(n**5)[-5:])