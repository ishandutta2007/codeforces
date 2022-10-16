x = int(input())
if x > 36:
        print(-1)
        exit()
print("8" * (x//2) + "6" * (x % 2))