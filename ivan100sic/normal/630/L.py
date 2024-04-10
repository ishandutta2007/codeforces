s = input()
s = s[0] + s[2] + s[4] + s[3] + s[1]
s = int(s) ** 5
print('{:05}'.format(s % 100000))