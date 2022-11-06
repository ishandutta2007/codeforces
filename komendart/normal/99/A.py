from math import floor

n, d = input().split('.')

if int(n) % 10 == 9:
    print("GOTO Vasilisa.")
elif int(d[0]) < 5:
    print(n)
else:
    print(int(n) + 1)