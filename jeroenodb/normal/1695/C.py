from sys import stdin
input = stdin.readline
#// - remember to add .strip() when input is a string

t = int(input())

for _ in range(t):

  n, m = map(int,input().split())
  grid = []

  for i in range(n):

    row = list(map(int,input().split()))

    grid.append(row)


  new = []
  for i in range(len(grid)):

    for j in range(len(grid[i])):

      new.append([i,j,grid[i][j]])



  #// max path
  DPmax = []

  for i in range(n):
    temp = []
    for j in range(m):
      temp.append(0)

    DPmax.append(temp)

  DPmax[0][0] = new[0][2]
  
  
  for i in range(1, len(new)):

    val1 = -float("inf")
    val2 = -float("inf")
    if new[i][0] - 1 >= 0:

      val1 = DPmax[new[i][0] - 1][new[i][1]]
      
    if new[i][1] - 1 >= 0:

      val2 = DPmax[new[i][0]][new[i][1] - 1]

    DPmax[new[i][0]][new[i][1]] = max(val1, val2) + grid[new[i][0]][new[i][1]]

  maxi = DPmax[-1][-1]

  #// min path

  DPmin = []

  for i in range(n):
    temp = []
    for j in range(m):
      temp.append(0)

    DPmin.append(temp)

  DPmin[0][0] = new[0][2]
  
  
  for i in range(1, len(new)):

    val1 = float("inf")
    val2 = float("inf")
    if new[i][0] - 1 >= 0:

      val1 = DPmin[new[i][0] - 1][new[i][1]]
      
    if new[i][1] - 1 >= 0:

      val2 = DPmin[new[i][0]][new[i][1] - 1]

    DPmin[new[i][0]][new[i][1]] = min(val1, val2) + grid[new[i][0]][new[i][1]]


  mini = DPmin[-1][-1]

  if mini <= 0 and maxi >= 0 and (mini%2==0 or maxi%2==0):

    print("YES")

  else:

    print("NO")