from decimal import *

getcontext().prec = 100
x = Decimal(input())
print(int(x) if x == int(x) else x)