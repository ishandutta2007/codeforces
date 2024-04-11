s = input()

s = s[1: -1].replace(',', '')

result = set(s.split())

print(len(result))