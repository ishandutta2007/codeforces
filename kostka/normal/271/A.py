n = int(input())

i = n
while True:
    i += 1
    if len(str(i))==len(set(str(i))):
        print(i)
        break